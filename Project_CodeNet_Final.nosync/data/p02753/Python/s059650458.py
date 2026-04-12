s=list(input())
cnt = 0
for i in s:
    for j in s:
        if i != j:
            cnt +=1

if cnt == 0:
    print('No')
else:
    print('Yes')