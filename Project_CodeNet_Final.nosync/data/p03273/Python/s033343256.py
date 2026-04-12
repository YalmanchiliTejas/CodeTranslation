h,w=map(int, input().split())
s = [list(input()) for i in range(h)]
s=[i for i in s if '#' in i]
count=0
while count<len(s[0]):
    check=0
    for i in s:
        if i[count]=='#':
            check=1
    if check==0:
        for i in s:
            i.pop(count)
    else:count+=1
for i in s:print(''.join(i))