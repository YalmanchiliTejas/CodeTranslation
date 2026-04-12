N = int(input())
S = [list(str(input())) for i in range(N)]
tmp = []
li = []
for i in range(N):
    tmp += S[i]
tmp = list(set(tmp))
for j in range(len(tmp)):
    flag = "True"
    count = 10**9
    for k in range(N):
        if S[k].count(tmp[j])==0:
            flag = "False"
            break
        else:
            count = min(S[k].count(tmp[j]),count)
    if flag=="True":
        for c in range(count):
            li.append(tmp[j])
li.sort()
print(''.join(li))