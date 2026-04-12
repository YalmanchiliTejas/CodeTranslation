h,w=map(int, input().split())

a=[]
for _ in range(h):
    # 追加の前に、行での除去を行う
    s=input()
    if not s.count(".")==w:
        a.append(list(s))
h=len(a)

j=0
while(j<len(a[0])):
    white_count=0
    for i in range(h):
        if a[i][j]=="#":
            j+=1
            break
        else:
            white_count+=1
    if white_count==h:
        for i in range(h):
            a[i]=a[i][:j] +a[i][j+1:]

for i in range(h):
    print("".join(a[i]))