n, x = (list)(map(int, input().split()))

patty = []
patty.append(1)

lay = []
lay.append(1)

for i in range(n):
    patty.append(patty[i]*2+1)
    lay.append(lay[i]*2+3)


# print(patty)
# print(lay)

c = 0

for i in reversed(range(n+1)):
 #   print("i,x,c=", i, x, c)
    if x == lay[i]:
      #      print("i")
        c += patty[i]
        break

    elif x == lay[i-1]+2:  # ちょうど半分の時
       #     print("elif1")
        c += patty[i-1]+1
        break
    elif x < lay[i-1]+2:  # 半分より小さい時
        #    print("elif2")
        x = x-1
    else:  # 半分より大きい時
     #   print("el")
        x = x-2-lay[i-1]
        c += patty[i-1]+1

print(c)
