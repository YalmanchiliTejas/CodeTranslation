def readinput():
    n=int(input())
    return n

def main(n):
    if n>=30:
        return 'Yes'
    else:
        return 'No'
    ans=0
    return ans

if __name__=='__main__':
    n=readinput()
    ans=main(n)
    print(ans)
