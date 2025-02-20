#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[]){
    double N[argc] = {};
    double sum = 0;
    if(argc == 1) cout << "Please input numbers to find average.";
    else{
        cout << "---------------------------------" << endl;
        for(int i = 1; i < argc; i++){
            N[i] = atof(argv[i]);
        }
        for(int i = 0; i < argc; i++){
            sum += N[i];
        }
        cout << "Average of " << argc - 1 << " numbers = " << sum/(argc-1) << endl;
        cout << "---------------------------------";
    }
}
