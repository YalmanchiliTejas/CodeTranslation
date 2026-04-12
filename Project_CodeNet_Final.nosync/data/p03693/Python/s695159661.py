def main():
    r, g, b = [ele for ele in input().split()]
    num=int(r+g+b)
    ans="NO"
    if num %4 == 0:
        ans = "YES"
    print(ans)




if __name__ == "__main__":
    main()