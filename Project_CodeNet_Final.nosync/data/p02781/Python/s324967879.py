n = input()
k = int(input())

if len(n) <= k:
    cnt = 0
    for i in range(1,int(n)+1):
        if len(str(i)) - str(i).count('0') == k:
            cnt += 1
    print(cnt)
    exit()

cnt = 0
l = len(n)
def combi(n,k):
    ans = 1
    if k == 0:
        return ans
    for i in range(k):
        ans = ans * (n-i) // (i+1)
    return ans
flag = 0
for i in range(l):
    if flag > k:
        break
    if n[i] == '0':
        if i == l-1 and k == flag:
            cnt += 1
        continue
    flag += 1
    cnt += int(((int(n[i])-1)*9**(k-flag))*combi(l-i-1,k-flag) + 9**(k-flag+1)*combi(l-i-1,k-flag+1))

print(cnt)