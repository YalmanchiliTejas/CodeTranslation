n = int(input())
l = [0] * n
for i in range(n):
    l[i] = int(input())
l.sort(reverse=True)
ans1 = 0
ans2 = 0
if n % 2 == 1:
    for i in range((n-3)//2):
        ans1 += 2 * l[i]
    ans1 += l[(n-3)//2] + l[(n-3)//2+1]
    for i in range((n-3)//2+2, n):
        ans1 -= 2 * l[i]

    for j in range((n-1)//2):
        ans2 += 2 * l[j]
    ans2 -= l[(n-1)//2] + l[(n-1)//2+1]
    for j in range((n-1)//2+2, n):
        ans2 -= 2 * l[j]

else:
    for i in range(((n-2)//2)):
        ans1 += 2 * l[i]
    ans1 += l[(n-2)//2]
    ans1 -= l[(n-2)//2+1]
    for i in range((n-2)//2+2, n):
        ans1 -= 2 * l[i]

ans = max(ans1, ans2)
print(ans)