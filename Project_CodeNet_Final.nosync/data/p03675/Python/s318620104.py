N = int(input())
A = list(map(int, input().split()))
odd = [A[i] for i in range(0, N) if not(i & 1)]
even = [A[i] for i in range(0, N) if i & 1]
ans = []
if N & 1:
    ans.extend(reversed(odd))
    ans.extend(even)
else:
    ans.extend(reversed(even))
    ans.extend(odd)
print(*ans)
