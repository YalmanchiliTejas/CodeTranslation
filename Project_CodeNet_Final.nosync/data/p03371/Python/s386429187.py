A,B,AB,X,Y= list(map(int, input().split()))
ans = (X * A) + (Y * B)
max_ab_cnt = max(X,Y)
for ab_cnt in range(max_ab_cnt+1):
    a_cnt = max(X - ab_cnt, 0)
    b_cnt = max(Y - ab_cnt,0)
    tmp = (a_cnt *A) + (ab_cnt * 2 * AB) + (b_cnt * B)
    ans = min(ans, tmp)
print(ans)