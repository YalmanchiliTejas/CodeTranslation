N = input()
mt_lst = list(map(int, input().split()))
cnt = 0

for i in range(len(mt_lst)):
    tmp = mt_lst[0:i+1]
    cnt += 1 if mt_lst[i] == max(tmp) else 0

print(cnt)
