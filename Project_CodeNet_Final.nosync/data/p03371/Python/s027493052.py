A, B, C, X, Y = [int(ax) for ax in input().split()]

mn_ABC = min(A+B, C*2)
mn_xy = min(X, Y)
money_1 = mn_ABC * mn_xy

money_2 = 0
if X > Y:
  mn_AC = min(A, C*2)
  money_2 = mn_AC * (X-Y)
elif X < Y:
  mn_BC = min(B, C*2)
  money_2 = mn_BC * (Y-X)

ans = money_1 + money_2
print(ans)