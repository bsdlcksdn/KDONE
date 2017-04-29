#include<iostream>
using namespace std;

int T, W;
int Tree[1010][2];
int DP[1010][31][2]; // tree_pos, count, now_pos


int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int recur(int tree_pos, int count, int now_pos) {

	if (tree_pos == T) {
		return 0;
	}

	int &ret = DP[tree_pos][count][now_pos];
	if (ret != -1) return ret;
	ret = 0;

	if (count < W) {
		if (now_pos == 1) {
			ret = max(ret, Tree[tree_pos][now_pos + 1] + recur(tree_pos + 1, count + 1, now_pos + 1));
		}
		else if (now_pos == 2) {
			ret = max(ret, Tree[tree_pos][now_pos - 1] + recur(tree_pos + 1, count + 1, now_pos - 1));
		}
	}

	ret = max(ret, Tree[tree_pos][now_pos] + recur(tree_pos + 1, count, now_pos));

}

int main() {

	cin >> T >> W;

	int num;
	for (int i = 0; i < T; i++) {
		cin >> num;
		Tree[i][num]++;
	}

	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 31; j++) {
			for (int z = 0; z < 2; z++) {
				DP[i][j][z] = -1;
			}
		}
	}

	cout << recur(0, 0, 1);

}