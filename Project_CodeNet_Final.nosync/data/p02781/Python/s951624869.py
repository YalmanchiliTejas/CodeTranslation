N=str(input())
K=int(input())
length=len(N)
dp=[[0]*10 for _ in range(length+1)]
dp[0][0]=1
def index(flag_less,k):
  if flag_less==0 and k==0:
    return 0
  elif flag_less==1 and k==0:
    return 1
  elif flag_less==0 and k==1:
    return 2
  elif flag_less==1 and k==1:
    return 3
  elif flag_less==0 and k==2:
    return 4
  elif flag_less==1 and k==2:
    return 5
  elif flag_less==0 and k==3:
    return 6
  elif flag_less==1 and k==3:
    return 7
  elif flag_less==0 and k==4:
    return 8
  else:
    return 9
  
for i in range(length):
  max_digit=int(N[i])
  for state in range(10):
    range_digit=9 if state%2 else max_digit
    for d in range(range_digit+1):          # 注意
      flag_less_next=0
      if state%2==1 or d<max_digit:
        flag_less_next=1
      prev_k=state//2
      if d!=0:
        next_k=min(4,prev_k+1)      
      else:
        next_k=prev_k
      next_state=index(flag_less_next,next_k)  # flag_less_next+2*next_kでもいい
      dp[i+1][next_state]+=dp[i][state]

print(dp[length][2*K]+dp[length][2*K+1])