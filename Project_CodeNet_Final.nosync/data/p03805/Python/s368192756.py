N, M = map(int, input().split())
E = [[] for _ in range(N)]

for _ in range(M):
	ta, tb = map(int, input().split())
	E[ta-1].append(tb-1)
	E[tb-1].append(ta-1)


def next_permutation(out, cnt, flg):
	if cnt == N:
		for i in range(N-1):
			if out[i+1] not in E[out[i]]:
				return 0
		return 1

	ans = 0

	for i in range(N):
		if flg[i] == 0:
			out.append(i)
			flg[i] = 1

			ans += next_permutation(out, cnt+1, flg)

			out.pop()
			flg[i] = 0

	return ans

perm = [0]
cnt = 1
flg = [0 for _ in range(N)]
flg[0] = 1

answer = next_permutation(perm, cnt, flg)

print(answer)