S = str(input())
K = int(input())
dp = [[[0, 0] for _ in range(4)] for _ in range(105)]
dp[0][0][0] = 1
# iは桁
# jはこれまでの非0の数
# kはNより小さいことが確定しているか否か

for i in range(len(S)):
	nxt_d = int(S[i])
	for j in range(4):
		for k in range(2):
			# 次入る数字を探す（判定）
			for d in range(10):
				nxt_i = i + 1
				nxt_j = j
				nxt_k = k
				if d != 0: # 非0の場合
					nxt_j += 1
				if nxt_j > K: # 非0の数が制限を超えちゃった
					continue
				if k == 0: # Nより小さいことが確定していない
					if d > nxt_d: continue
					if d < nxt_d: nxt_k = 1
				dp[nxt_i][nxt_j][nxt_k] += dp[i][j][k]
ans = dp[len(S)][K][0] + dp[len(S)][K][1]

print(ans)