#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double arr[], int N, double B[]) {
    double sum = 0.0;

    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    B[0] = sum / N;

    double variance = 0.0;
    for (int i = 0; i < N; i++) {
        variance += pow(arr[i] - B[0], 2);
    }
    B[1] = sqrt(variance / N);

    double product = 1.0;
    bool has_nonpositive = false;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= 0) {
            has_nonpositive = true;
            break;
        }
        product *= arr[i];
    }
    if (has_nonpositive) {
        B[2] = 0;
    } else {
        B[2] = pow(product, 1.0 / N);
    }

    double harmonic_sum = 0.0;
    bool has_zero = false;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            has_zero = true;
            break;
        }
        harmonic_sum += 1.0 / arr[i];
    }
    if (has_zero) {
        B[3] = 0;
    } else {
        B[3] = N / harmonic_sum;
    }

    B[4] = *max_element(arr, arr + N);
    B[5] = *min_element(arr, arr + N);
}
