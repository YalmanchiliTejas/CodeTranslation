n,k= map(int, input().split())
if n == k :
    print("Yes")
else:
    print("No")

# p = list(map(int,input().split()))

# count = 0
# val = sum(p[0:k])
# val_lis = [val]
# mx_val = val
# index = 0
# mx_index = 0
# for i,j in enumerate(p[k:]):
#     val = val - p[index] + j
#     val_lis.append(val)
#     index +=1
#     if val > mx_val:
#         mx_index = index
#         mx_val = val 
    
# ans = 0
# for i in range(k):
#     ans += ((p[mx_index + i]+1.0)*(p[mx_index+i]))/ (p[mx_index+i] *2.0)
# print(ans)  




# h = sorted(h,reverse = True)
# print(sum(h[k:]))

# s,t= map(str, input().split())
# a,b= map(int, input().split())
# u = input()
# print("x"*len(u))

# if(u == s):
#     print(a-1,b)
# else:
#     print(a,b-1)
