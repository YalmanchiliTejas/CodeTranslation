"""
Writer: SPD_9X2
https://atcoder.jp/contests/abc128/tasks/abc128_f

左端から一定個数おきにおいていく(好きな個数だけ)。
これを中心に対して反転したときに、重ならないならば、反転してor演算したものは構成可能
あとは、1～N-1に関して約数を探索するので計算量は
O(N√N)

コーナーケースっぽいwa!!
→うーんなんだろう？
→半分以上に関しては不可能なので、0にしておくべき？

左から並べたやつの右端より右に少なくとも1つの右が必要
"""

N = int(input())

s = list(map(int,input().split()))
now = [0] * N
ans = [0] * N

for i in range(1,N):

    j = 1

    while j ** 2 <= i:

        if i % j == 0:

            if (N-1) % j == 0 and 2+i*2 > N:
                pass
            elif i + j > N:
                pass
            else:
                #print (i,j)
                now[j] += s[i] + s[N-1-i]
                ans[j] = max(ans[j],now[j])

        if i % j == 0 and j**2!=i:

            j2 = i // j

            if (N-1) % j2 == 0 and 2+i*2 > N:
                pass
            elif i+j2 > N:
                pass
            else:
                #print (i,j2)
                now[j2] += s[i] + s[N-1-i]
                ans[j2] = max(ans[j2],now[j2])

        j+=1
    #print (now)

pra = 0
for i in range(0,N//2):
    pra = max(pra,ans[i])

#print (ans)
print (pra)
            

    

