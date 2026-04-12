#Kが3種類なので、分岐を全て書く
#桁数をa、最上位の桁をbとし、その値で場合分け
#最上位が0場合、最上位が0以上b未満の場合(最上位が0は個数も0のため重複されない)、最上位がbで残りのa-1桁でK-1にして再帰
def ans(n,k):
  s=str(n)
  a=len(s)
  b=int(s[0])
  if(k==1):
    return 9*(a-1)+b
  elif(k==2):
    return int(81*(a-1)*(a-2)/2)+9*(b-1)*(a-1)+ans(n-b*10**(a-1),1)
  else:
    return int(729*(a-1)*(a-2)*(a-3)/6)+int(81*(b-1)*(a-1)*(a-2)/2)+ans(n-b*10**(a-1),2)

N=int(input())
K=int(input())
print(ans(N,K))