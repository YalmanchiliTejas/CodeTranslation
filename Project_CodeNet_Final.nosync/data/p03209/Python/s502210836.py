n,x=map(int,input().split())

thickness=[1]
for i in range(1,n):
    thickness.append(2*thickness[i-1]+3)
patty=[1]
for i in range(1,n):
    patty.append(2*patty[i-1]+1)


def pattyCnt(n,x):
    if n==0:
        return 0 if x<=0 else 1
    elif x<=1+thickness[n-1]:
        return pattyCnt(n-1,x-1)
    else:
        return patty[n-1]+1+pattyCnt(n-1,x-2-thickness[n-1])

print(pattyCnt(n,x))