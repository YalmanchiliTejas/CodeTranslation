def main():
  N,S = map(int,input().split())
  A = list(map(int,input().split()))
  MOD = 998244353

  # サンプル3 4 2,2,4の場合、P1=1+x^2,P2=1+x^2,P3=1+x^4とすると、解は
  # P1P2P3+P1P2+P2P3+P1P3+P1+P2+P3におけるx^4の係数となる。
  # Q1=P1,Q2=P2+P1P2,Q3=P3+P2P3+P1P2P3とすると、
  # P1P2P3+P1P2+P2P3+P1P3+P1+P2+P3=Q1+Q2+Q3
  # Q1=P1(1+0)
  # Q2=P2(1+Q1)
  # Q3=P3(1+Q2)
  # 今のQに1を足してからPを掛けて、次のQを求める。
  # 解は、それぞれのQのx^4の係数を足していけばよい。
  ans = 0
  q = [0 for _ in range(S+1)]
  for i in range(len(A)):
    q[0] += 1
    q[0] %= MOD
    q2 = q[:]
    for j in range(S):
      if j+A[i] <= S:
        q2[j+A[i]] += q[j]
        q2[j+A[i]] %= MOD
    q = q2[:]
    ans += q[S]
  #print(q)
  print(ans%MOD)
  
main()