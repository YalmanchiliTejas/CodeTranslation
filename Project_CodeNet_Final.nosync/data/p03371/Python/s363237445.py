a,b,c,x,y = map(int, input().split())

#A,Bだけで買う場合
bill_ab = a * x + b * y

#少ないほうはCで賄う場合
if x <= y:
  bill_abc = x * 2*c + (y - x) * b
else:
  bill_abc = y * 2*c + (x - y) * a

bill_c = max(x,y) * 2*c


print(min(bill_ab, bill_abc, bill_c))
