alp=['************','*qwertyuiop*','*asdfghjkl**','*zxcvbnm****','************']
_alp=''.join(alp)
def check(now,nxt):
    a,b=_alp.find(now)//12,_alp.find(now)%12
    c,d=_alp.find(nxt)//12,_alp.find(nxt)%12
    q1=_log[-1]
    q2='L' if d<=5 else 'R'
    log.append(q2)
    if abs(a-c) + abs(b-d)<=1 :
        _log.append(q1)
    else:
        _log.append(q2)

while 1:
    s=input()
    if s=='#':
        break
    log=['L' if _alp.find(s[0])%12<=5 else 'R']
    _log=[log[0]]
    for i in range(len(s)-1):
        check(s[i],s[i+1])
    
    count=0
    for x,y in zip(log,_log):
        if x!=y:
            count+=1
    c=log[0]
    ans=0
    for v in log:
        if c!=v:
            c=v
            ans+=1
    print(ans)
    
