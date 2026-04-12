def main():
  N = int(input())
  A_lst = list(map(int, input().split()))
  
  sum = 0
  for i in A_lst:
    sum += i
    sum = sum % (10**9 + 7)
  
  sum2 = 0
  for j in A_lst:
    sum = ((sum-j) % (10**9 + 7))
    sum2 += j * sum
    sum2 = sum2 % (10**9 + 7)

  print(sum2)
  
main()