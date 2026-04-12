def method3():
    n = (int(input()))
    nums = list(map(int, input().split()))
    result = 1
    hantei = True
    for i in range(1,n):
        hantei = True
        for j in range(i):
            if nums[i]<nums[j]:
                hantei = False
                break
        if hantei:
            result = result + 1
    print(result)
    
if __name__ == "__main__":
    method3()