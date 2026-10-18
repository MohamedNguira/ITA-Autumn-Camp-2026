#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> answer;

bool check(vector<int> positions) {
    if (positions.empty())
        return true;
    // Check if by adding the last queen, does the combination become invalid?
    int new_col = positions.back(), new_row = positions.size() - 1;
    // Horizontal Check
    // Not necessary

    // Vectical Check
    for (int i = 0; i < positions.size()-1; i++) {
        int col = positions[i];
        if (col == new_col) {
            return false;
        }
    }

    // Diagonal Check
    for (int i = 0; i < positions.size()-1; i++) {
        int col = positions[i], row = i;
        int dis1 = abs(col - new_col);
        int dis2 = abs(row - new_row);
        if (dis1 == dis2) {
            return false;
        }
    }
    return true;
}
bool solve(vector<int> positions) {
    // Main recursive solver

    if (!check(positions)) {
        return false;
    }
    // Base case
    // All queens were placed
    if (positions.size() == n) {
        // All queens are placed
        answer = positions;
        return true;
    }
    for (int i = 0; i < n; i++) {
        positions.push_back(i);
        // Recursive call
        bool solved = solve(positions);
        if (solved) {
            return true;
        }
        positions.pop_back();
    }
    return false;
}

int main() {


    cin >> n;
    /*
     * Given n, Print a grid containing the positions of the queens
     * Example:
     * n = 4
     * *Q**
     * ***Q
     * Q***
     * **Q*
     */
    bool solved = solve({});
    if (!solved) {
        cout << "Solution not found" << endl;
    }
    else {
        for (int i = 0; i < n; i++) {
            // print whole row:
            for (int j = 0; j < n; j++) {
                if (answer[i] == j) {
                    cout << 'Q';
                }
                else cout << '*';
            }
            cout << endl;
        }
    }
    return 0;
}
// Complexity of the code: O(n!)
// n! = n * (n-1) * (n-2) ... * 2 * 1