N = int(input())
A = list(map(int, input().split()))

S = sum(A)
S_2 = sum(map(lambda x: x*x, A))

ans = (S*S - S_2)//2 #切り捨て除算にしないと結果をfloatで返してきやがるので

print(ans%(10**9 + 7))