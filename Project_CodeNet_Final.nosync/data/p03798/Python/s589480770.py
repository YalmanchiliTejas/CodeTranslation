#最初の2匹を割り当てることで解答文字列ansは一意に決まる。
#最初に[SW][WS][SS][WW]の4通りで決めウチすることで円環の接続点を見比べることができる
#脳死で4パターン同じ処理をコピペ。

N=int(input())
S=input()

def solve(n,s):

#[SW]の場合
  ans="SW"
  if s[0]=="o":
    ch="W"
  else:
    ch="S"
  for i in range(1,n):
    if (ans[-1]=="S" and s[i]=="o") or (ans[-1]=="W" and s[i]=="x") :
      ans = ans + ans[-2]
    elif ans[-1]=="S" and s[i]=="x" and ans[-2]=="S":
      ans = ans + "W"
    elif ans[-1]=="S" and s[i]=="x" and ans[-2]=="W":
      ans = ans + "S"
    elif ans[-1]=="W" and s[i]=="o" and ans[-2]=="S":
      ans = ans + "W"
    else:
      ans = ans + "S"
  if ans[-2]==ch and ans[-1]==ans[0]:
    return ans[:-1]

#[WS]の場合
  ans="WS"
  if s[0]=="o":
    ch="W"
  else:
    ch="S"
    
  for i in range(1,n):
    if (ans[-1]=="S" and s[i]=="o") or (ans[-1]=="W" and s[i]=="x") :
      ans = ans + ans[-2]
    elif ans[-1]=="S" and s[i]=="x" and ans[-2]=="S":
      ans = ans + "W"
    elif ans[-1]=="S" and s[i]=="x" and ans[-2]=="W":
      ans = ans + "S"
    elif ans[-1]=="W" and s[i]=="o" and ans[-2]=="S":
      ans = ans + "W"
    else:
      ans = ans + "S"
  if ans[-2]==ch and ans[-1]==ans[0]:
    return ans[:-1]
  
#[SS]の場合
  ans="SS"
  if s[0]=="o":
    ch="S"
  else:
    ch="W"
    
  for i in range(1,n):
    if (ans[-1]=="S" and s[i]=="o") or (ans[-1]=="W" and s[i]=="x") :
      ans = ans + ans[-2]
    elif ans[-1]=="S" and s[i]=="x" and ans[-2]=="S":
      ans = ans + "W"
    elif ans[-1]=="S" and s[i]=="x" and ans[-2]=="W":
      ans = ans + "S"
    elif ans[-1]=="W" and s[i]=="o" and ans[-2]=="S":
      ans = ans + "W"
    else:
      ans = ans + "S"
  if ans[-2]==ch and ans[-1]==ans[0]:
    return ans[:-1]
  
#[WW]の場合
  ans="WW"
  if s[0]=="o":
    ch="S"
  else:
    ch="W"
    
  for i in range(1,n):
    if (ans[-1]=="S" and s[i]=="o") or (ans[-1]=="W" and s[i]=="x") :
      ans = ans + ans[-2]
    elif ans[-1]=="S" and s[i]=="x" and ans[-2]=="S":
      ans = ans + "W"
    elif ans[-1]=="S" and s[i]=="x" and ans[-2]=="W":
      ans = ans + "S"
    elif ans[-1]=="W" and s[i]=="o" and ans[-2]=="S":
      ans = ans + "W"
    else:
      ans = ans + "S"
  if ans[-2]==ch and ans[-1]==ans[0]:
    return ans[:-1]
  
  return -1

print(solve(N,S))