n = int(input())
alist = list(map(int,input().split()))
wa = sum(alist)
answer = 0
atai = wa
for i in range(n):
    atai -= alist[i]
    answer += atai * alist[i]
    answer = answer % (10**9 + 7)
print(answer)