#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

void compressFile(string input, string output) {
    ifstream in(input);
    ofstream out(output);

    char prev, curr;
    int count = 1;

    if (!in.get(prev)) return;

    while (in.get(curr)) {
        if (curr == prev)
            count++;
        else {
            out << prev << count;
            prev = curr;
            count = 1;
        }
    }
    out << prev << count;

    in.close();
    out.close();
}

int main() {
    thread t1(compressFile, "input.txt", "compressed.txt");
    t1.join();

    cout << "File compressed using multithreading.\n";
    return 0;
}