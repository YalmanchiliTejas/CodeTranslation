N = int(input())
A = list(map(int, input().split()))
B = list(a ** 2 for a in A)
m = 10 ** 9 + 7
ans = int((sum(A) ** 2) // 2)
ans %= m
ans -= int(sum(B) // 2)
ans %= m
print(ans)