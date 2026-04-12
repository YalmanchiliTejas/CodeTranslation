N,K = map(int,input().split())

# a = b * x + K
# bを固定してaを1~Nまで動かしたとき、aをbで割った余りは1,2...b-1,0のb通り。
# その中にK以上の余りはb-K通り。
# 余りを順に並べると、1,2...b-1,0,1,2...b-1,0,1,2...N%b となる。
# 1,2...N%b の中にK以上の数はN%b-K+1通り。
# 1,2...b-1,0はN//b回繰り返される。
# Kが0のときは、a,bはどんな組み合わせでもいいからN**2通り。

if K == 0:
  print(N**2)
  exit()
ans = 0
for b in range(1,N+1):
  if b-K > 0:
    ans += (b-K)*(N//b)
  if N%b-K+1 > 0:
    ans += N%b-K+1
print(ans)