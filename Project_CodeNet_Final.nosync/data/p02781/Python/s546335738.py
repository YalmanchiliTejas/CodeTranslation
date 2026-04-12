import math

n = int(input())
k = int(input())

def combinations_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

def count(num_str,k):
    digits = len(num_str)
    if digits == 0:
        return 0
    else:
        if k == 0:
            # print(num_str,1)
            return 1
        if num_str[0] == '0':
            # print(num_str,count(num_str[1:],k-1))
            return count(num_str[1:],k)
        else:
            if digits == 1 and k == 1:
                # print(num_str,int(num_str))
                return int(num_str)
            elif digits == 1 and k > 1:
                # print(num_str,0)
                return 0
            if digits >= k+1:
                count_0 = combinations_count(digits-1,k)*(9**k)
            else:
                count_0 = 0
            count_1 = combinations_count(digits-1,k-1)*(9**(k-1))
            # print(num_str,count_0 + count_1*(int(num_str[0])-1)+count(num_str[1:],k-1))
        return count_0 + count_1*(int(num_str[0])-1)+count(num_str[1:],k-1)

print(count(str(n),k))