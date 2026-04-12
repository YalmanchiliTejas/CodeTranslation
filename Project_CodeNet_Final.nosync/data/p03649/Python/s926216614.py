n = int(input())
A = list(int(x) for x in input().split())
ans = 0
while max(A) >= n:
    m = max(A)
    index = A.index(m)
    count = m // n
    ans += count
    A = [a + count for a in A]
    A[index] -= n * count + count

print(ans)