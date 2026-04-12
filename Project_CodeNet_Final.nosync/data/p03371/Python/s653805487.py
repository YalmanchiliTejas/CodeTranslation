A,B,C,X,Y=map(int,input().split())

def dp(num_a,num_b):
    """
    if num_a<=0 and num_b<=0:return 0
    elif num_b>0:
        if B<2*C:return B+dp(num_a,num_b-1)
        else :return C*2+dp(num_a-1,num_b-1)
    else:
        if A<2*C:return A+dp(num_a-1,num_b)
        else: return C*2+dp(num_a-1,num_b-1)
    """
    if A+B>2*C:
        if min(num_a,num_b)>0:
            if num_a > num_b:
                return num_b*2*C+dp(num_a-num_b,0)
            else :
                return num_a*2*C+dp(0,num_b-num_a)
        elif num_a==0 and num_b>0:
            if B<2*C:
                return num_b*B
            else :
                return C*2*num_b
        elif num_a>0 and num_b==0:
            if A<2*C:
                return A*num_a
            else :
                return 2*C*num_a
        else :
            return 0
    else :
        return num_a*A+num_b*B
print(dp(X,Y))