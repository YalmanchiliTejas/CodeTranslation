t,s,e,w,n,b = [1,2,3,4,5,6]
def north():
    global t,s,e,w,n,b
    t,n,b,s = s,t,n,b
def east():
    global t,s,e,w,n,b
    t,e,b,w = w,t,e,b
def west():
    global t,s,e,w,n,b
    t,w,b,e = e,t,w,b
def south():
    global t,s,e,w,n,b
    t,s,b,n = n,t,s,b
def right():
    global t,s,e,w,n,b
    e,n,w,s = n,w,s,e
def left():
    global t,s,e,w,n,b
    e,s,w,n = s,w,n,e
dic = {"North":north,"East":east,
       "West":west,"South":south,
       "Right":right,"Left":left}
while True:
    N = input()
    if N == 0:
        break
    t,s,e,w,n,b = [1,2,3,4,5,6]
    ans = 1
    for i in xrange(N):
        dic[raw_input().strip()]()
        ans += t
    print ans