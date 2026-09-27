#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Given a sorted array, find two values
    //that sums up to a number 'k'
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, obj;
    cin >> x;
    int ar[x];
    for (int i = 0; i < x; i++)
    {
        cin >> ar[i];
    }
    int esq = 0, dir = x - 1;
    cin >> obj;
    while (ar[esq] + ar[dir] != obj)
    {
        if (ar[esq] + ar[dir] < obj)
        {
            esq++;
        }
        else if (ar[esq] + ar[dir] > obj)
        {
            dir--;
        }
        else
        {
            break;
        }
    }
    cout << ar[esq] << ' ' << ar[dir] << '\n';

    return 0;
}
