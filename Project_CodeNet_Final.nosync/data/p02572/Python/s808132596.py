N = int(input())
L = list(map(int, input().split()))

Ans = 0

sum_L = L[0]

l = len(L)

for i in L[1:]:
    Ans += sum_L*i%(10**9+7)
    sum_L += i
Ans = Ans%(10**9+7)
print(Ans)