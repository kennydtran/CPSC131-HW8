#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

class hashtable {
public:
    vector<forward_list<int>> v;

    int code(unsigned int key) {
        return key;
    }
    size_t h(int code) {
        int prime_num = 2^64 - 1;
        int result = code % prime_num;
        return result;
    }
    size_t hash(int Key) {
        return h(code(Key));
    }

    hashtable() : v(12) {}

    void insert(int value)
    {
        int i = hash(value);
        v[i].push_front(value);
    }

    void printTable()
    {
        for (int i = 0; i < 12; i++)
        {

            for (auto x : v[i])
            {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    hashtable h2;
    int v2[] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (int i = 0; i < 11; i++)
    {
        h2.insert(v2[i]);

    }
    h2.printTable();
    return 0;
}
