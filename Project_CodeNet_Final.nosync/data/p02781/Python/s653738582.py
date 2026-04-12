N = int(input())
Y = list(str(N))
Z =[]
for i in Y:
    Z.append(int(i))
K = int(input())
m = len(str(N))
def nn(Z,K,m):
    ans = 0
    if m < K:
        return ans
    else:
        if K == 1:
            y = Z[0]
            ans += (m-1) * 9 + y
            #print(ans)
        elif K == 2:
            #0 
            ans += ((m-1) * (m-2) // 2) * 9 * 9
            #print(ans)
            #mid
            ans += (max(0,Z[0]-1)) * (m-1) * 9
            #print(ans)
            #max
            K -= 1
            m -= 1
            Z = Z[1:]
            for _ in range(100):
                if Z[0] == 0:
                    m -= 1
                    Z = Z[1:]   
                else:
                    break
                if len(Z) == 0:
                    break            
            ans += nn(Z,K,m)
            #print(ans)
        elif K == 3:
            #0 
            ans += ((m-1) * (m-2) * (m-3) // 6) * 9 * 9 * 9
            #print(ans)
            #mid
            ans += (max(0,Z[0]-1)) * ((m-1) * (m-2) // 2) * 9 * 9
            #print(ans)
            #max
            K -= 1
            m -= 1
            Z = Z[1:]
            for _ in range(100):
                if Z[0] == 0:
                    m -= 1
                    Z = Z[1:]   
                else:
                    break
                if len(Z) == 0:
                    break
            ans += nn(Z,K,m)
        return ans
if len(str(N)) < K:
    ans = 0
else:
    ans = nn(Z,K,m)        
print(ans)