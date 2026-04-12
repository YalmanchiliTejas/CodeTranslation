import math

def combinations_count(n, r):
  if n>=r:
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
  else:
    return 0

str_n=input()
k=int(input())
cnt=0
dig = len(str_n)

#最上位桁が最大以外の場合　かつ　0でない場合
cnt += (int(str_n[0])-1)*combinations_count(dig-1,k-1)*9**(k-1)
#最上位桁が0の場合
if dig-1>=k:
  cnt += combinations_count(dig-1,k)*9**k

#最上位桁が最大の場合
if k==1:
  cnt+=1
else:
  ##第２非ゼロ桁の探索
  for i in range(dig-1):
    if str_n[i+1] != '0':
      dig2 = i+1
      break
  else:
    print(cnt)
    exit()
  ##第２非ゼロ桁が最大以外の場合　かつ　0でない場合
  cnt += (int(str_n[dig2])-1)*combinations_count(dig-1-dig2,k-2)*9**(k-2)
  ##第２非ゼロ桁が0の場合
  if dig-1-dig2>=k-1:
    cnt += combinations_count(dig-1-dig2,k-1)*9**(k-1)
  ##第２非ゼロ桁が最大の場合
  if k==2:
    cnt+=1
  else:
    ##第３非ゼロ桁の探索
    for i in range(dig-1-dig2):
      if str_n[i+1+dig2] != '0':
        dig3 = i+1+dig2
        break
    else:
      print(cnt)
      exit()
    ##第３非ゼロ桁が0でない場合
    cnt += int(str_n[dig3])
    ##第３非ゼロ桁が0の場合
    cnt += combinations_count(dig-1-dig3,k-2)*9**(k-2)
print(cnt)