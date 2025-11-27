#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

double fungsiFx(double x) {
   return pow(x, 3) - pow(x, 2) + (2 * x) - (x * exp(-2 * x)) - (2 * exp(-2 * x));

}

double fungsiTurunan(double x) {
   return (2 * (x + 2) * exp(-2 * x) - exp(-2 * x) + pow(x, 2) - (2 * x) + 2);
}
 
double F1x(double x) {
   return (x * x) - (2 * x) + 1;
}

int main() {
   int iter, i = 0;
   double e, x0, er;

   cout << "Input nilai x0 = ";
   cin >> x0;
   cout << "Input nilai error toleransi e = ";
   cin >> e;
   cout << "Jumlah iterasi : ";
   cin >> iter;
   
   cout<<"-------------------------------------------------------------------\n";
   cout<<"|i     |x0            |f(x0)            |f'(x0)        |xi        |\n";
   cout<<"-------------------------------------------------------------------\n";
   
   double xi, y;
   do {
      xi = x0 - (fungsiFx(x0) / fungsiTurunan(x0));
      er = abs(fungsiFx(x0));
      cout << left << setw(8) << i << setw(15) << x0 << setw(18) << fungsiFx(x0) << setw(15) << fungsiTurunan(x0) << setw(18) << xi << "\n";
      x0 = xi;
      i++;
   } while (er > e && i < iter);
   y = F1x(xi);
   cout << "Stop!!" << "\n";
   cout << "Sehingga didapatkan titik potong (x, y) = (" << xi << ", " << y << ")";
   
   return 0;
}