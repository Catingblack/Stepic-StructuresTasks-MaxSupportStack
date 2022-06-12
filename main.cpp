#include <iostream>
#include <string>

using namespace std;


void copyMass(int* in, int* out, int n) {
    for(int i = 0; i < n; i++) {
        in[i] = out[i];
    }
}

struct stack {

    int size;
    int n = 1000;
    int* Arr;
    int* mArr;

    stack() {
        size = 0;
        Arr = new int[n];
        mArr = new int[n];
    }

    void push(int v) {
        int mx;
        int* ArrCpy;
        int* mArrCpy;


        if(size > n) {
            ArrCpy = new int[2*n];
            mArrCpy = new int[2*n];
            copyMass(ArrCpy, Arr, size);
            copyMass(mArrCpy, mArr, size);
            delete [] Arr;
            delete [] mArr;
            Arr = new int[2*n];
            mArr = new int[2*n];
            copyMass(Arr, ArrCpy, size);
            copyMass(mArr, mArrCpy, size);
            delete [] ArrCpy;
            delete [] mArrCpy;
        }

        if(size == 0) {
            size = 1;
            Arr[0] = v;
            mArr[0] = v;
        }

        else {
            mx = mArr[size - 1];
            size = size + 1;

            if(v > mx) {
                mArr[size - 1] = v;
            }
            else {
                mArr[size - 1] = mx;
            }

            Arr[size - 1] = v;
        }

    }

    int pop() {
        int res = Arr[size - 1];

        size = size - 1;

        return res;
    }

    int front() {
        return Arr[size-1];
    }

    void max() {
        int mx = mArr[size - 1];

        cout << mx << endl;
    }

    int empty() {
        if(size == 0) {
            return 1;
        }
        return -1;
    }


    ~stack() {
        delete [] Arr;
        delete [] mArr;
    }
};

int main()
{
    stack myStack;
    string s;
    int n;
    int v;

    cin >> n;


    for(int i = 0; i < n; i++) {
        cin >> s;

        if(s == "push") {
            cin >> v;
            myStack.push(v);
        }
        if(s == "pop") {
            myStack.pop();
        }
        if(s == "max") {
            myStack.max();
        }
    }


    return 0;
}
