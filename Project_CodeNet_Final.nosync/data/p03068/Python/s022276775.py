n = int(input())
S = input()
k = int(input())
func = lambda x : x if x == S[k-1] else "*"
print(*[func(s) for s in S],sep="")