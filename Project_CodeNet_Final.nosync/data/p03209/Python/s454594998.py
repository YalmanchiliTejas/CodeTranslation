n,x=map(int,input().split())
p=[1]
q=[1]
for i in range(n):
    p.append(2*p[i]+1)
    q.append(2*q[i]+3)
def cal(n_cal,x_cal):
    if x_cal==0:
        ret=0
    elif n_cal==0 and x_cal==1:
        ret=1
    elif x_cal==1:
        ret=0
    elif 1<x_cal<=q[n_cal-1]+1:
        ret=cal(n_cal-1,x_cal-1)
    elif  q[n_cal-1]+2==x_cal:
        ret=(p[n_cal-1]+1)
    elif x_cal<=2+q[n_cal-1]*2:
        ret=p[n_cal-1]+1+cal(n_cal-1,x_cal-(q[n_cal-1]+2))
    elif x_cal==3+2*q[n_cal-1]:
        ret=2*p[n_cal-1]+1
    return ret
print(cal(n,x))
