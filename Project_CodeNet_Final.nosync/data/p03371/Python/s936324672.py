def calc_ans(a,b,c,x,y):
    #2. candidate
    less = min([x,y])
    if less == y:
        use_c = 2*c*less + a*(x-less)
    else:
        use_c = 2*c*less + b*(y-less)
        
    not_use_c = a*x + b*y
    
    only_c = 2*c*max([x,y])
    
    return min([use_c, not_use_c, only_c])

def main():
    #1.input
    a,b,c,x,y = map(int, input().split())
    
    
    ans = calc_ans(a,b,c,x,y)
    print(ans)

if __name__ == "__main__":
    main()