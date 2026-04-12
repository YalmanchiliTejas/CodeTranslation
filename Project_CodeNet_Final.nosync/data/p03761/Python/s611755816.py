n = int(input())
ans = list(input())
for i in range(n - 1):
    t = list(input())
    j = 0
    while j < len(ans):
        k = 0
        while k < len(t):
            if ans[j] == t[k]:
                del t[k]
                break
            else:
                k += 1
        else:
            del ans[j]
            j -= 1
        j += 1
ans.sort()
print("".join(ans))
