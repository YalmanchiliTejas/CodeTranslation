N,X,M = map(int,input().split())

ans = X
A = X
TF = True
srt = 1000000
retu = [X]
d = dict()
d[X] = 0
loop = X
flag = False
for i in range(N-1):
    if TF:
        A = A**2 % M
        if d.get(A) != None:
          srt = d[A]
          goal = i
          TF = False
          
        if TF:
          retu.append(A)
          d[A] = i + 1
          loop += A
    else:
      flag = True
      break
      
if flag:
    n = (N-srt)//(goal-srt+1)
    saisyo = sum(retu[:srt])
    loop -= saisyo
    print(saisyo + loop*n + sum(retu[srt:N-n*(goal-srt+1)]))
    
else:
    print(sum(retu[:N]))
