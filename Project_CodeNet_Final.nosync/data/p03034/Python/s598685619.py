n = int(input())
s = list(map(int, input().split()))
max_val = 0
for diff in range(1, n):
    visited = set()

    j = n - 1 - diff
    i = diff

    val = 0
    while i < n - 1 - diff and j > diff :
        if j in visited or i in visited or j == i:
            break
        visited.add(j)
        visited.add(i)
        val += s[j] + s[i]
        i += diff
        j -= diff
        if max_val < val:
            max_val = val
print(max_val)