#include<iostream>
#include <map>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<int, int>> intervals(n);
    for (auto& [a, b] : intervals)
        cin >> a >> b;

    map<pair<int, int>, int> index;

    for (int i = 0; i < n; i++)
        index[intervals[i]] = i;

    {
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });

        vector<int> outer(n);
        set<int, greater<>> bounds;
        for (int i = 0; i < n; i++) {
            auto [a, b] = intervals[i];
            auto it = bounds.lower_bound(b);
            if (it != bounds.end()) outer[index[intervals[i]]] = 1;
            bounds.insert(b);
        }

        for (int i = 0; i < n; i++) cout << outer[i] << " ";
        cout << endl;
    }

    {
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        });

        vector<int> inner(n);
        set<int> bounds;
        for (int i = 0; i < n; i++) {
            auto [a, b] = intervals[i];
            auto it = bounds.lower_bound(b);
            if (it != bounds.end()) inner[index[intervals[i]]] = 1;
            bounds.insert(b);
        }

        for (int i = 0; i < n; i++) cout << inner[i] << " ";
        cout << endl;
    }
}