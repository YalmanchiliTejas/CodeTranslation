N = int(input())
 
num_list = []
for _ in range(N):
    num_list.append(int(input()))
    
num_sorted = sorted(num_list)
 
def calc_diff(add, add2, diff, diff2, num_sorted):
    total = 0
    
    for _ in range(add2):
        tmp = num_sorted.pop()
        total += tmp * 2
        
    for _ in range(add):
        tmp = num_sorted.pop()
        total += tmp * 1
        
    for _ in range(diff):
        tmp = num_sorted.pop()
        total -= tmp * 1
            
    for _ in range(diff2):
        tmp = num_sorted.pop()
        total -= tmp * 2
        
    return total
  
import copy
 
def calc(N, num_sorted):
    
    diff2 = 0
    add2 = 0
    diff = 0
    add = 0
    
    if N % 2 == 0:
        add = 1
        diff = 1
        add2 = N // 2 - 1
        diff2 = N // 2 - 1
        
        total = calc_diff(add, add2, diff, diff2, copy.deepcopy(num_sorted))
 
        return total
            
    if N % 2 == 1:        
        add = 0
        diff = 2
        add2 =(N - 1) // 2
        diff2 = (N - 1) // 2 - 1
        
        totalB = calc_diff(add, add2, diff, diff2, copy.deepcopy(num_sorted))
        
        add = 2
        diff = 0
        add2 =(N - 1) // 2 - 1
        diff2 = (N - 1) // 2
        
        totalC = calc_diff(add, add2, diff, diff2, copy.deepcopy(num_sorted))
        
        return max(totalB, totalC)
      
print(calc(N, num_sorted))