N = int(input())
S = list(input())
K = int(input())
moji = S[K-1]
for i in range(N):
	S[i] = "*" if S[i] != moji else S[i]
new_moji = "".join(S)
print(new_moji)