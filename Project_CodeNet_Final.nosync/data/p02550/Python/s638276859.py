def main():
    n,x,m = map(int,input().split())
    R = [x]
    g = set([x])
    for i in range(1,min(m,n)):
        x = x**2 % m
        if not x in g:
            R.append(x)
            g.add(x)
        else:
            break
    
    R_ac = [0]*(len(R)+1)
    for i in range(len(R)):
        R_ac[i+1] = R_ac[i] + R[i]

    j = R.index(x)
    ct = n
    
    ans = R_ac[j]
    ct-=j

    q = ct//(len(R)-j)
    ans+= q*(R_ac[-1]-R_ac[j]) 
    ct-=q*(len(R)-j)

    ans+= R_ac[j+ct] - R_ac[j]

    print(ans)
main()