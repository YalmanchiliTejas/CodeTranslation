import math
import decimal
import queue
import bisect
import heapq
import time
import itertools

mod = int(1e9+7)

class Library():
    @staticmethod
    def Swap(a,b):
        return [b,a]

    @staticmethod
    def myRound(a,dig=0): # 四捨五入
        p = 10 ** dig
        return (a * p * 2 + 1) // 2 / p

    @staticmethod
    def Roundup(a,dig=0): # 切り上げ
        if a < 0:
            return int(a)
        else:
            return int(a + 0.9)

    @staticmethod
    def Gcd(a,b): #最大公約数
        if (a<b):
            a,b = Library.Swap(a,b)
        if (b==0):
            return a
        else:
            return Library.Gcd(b,a%b)

    @staticmethod
    def Lcm(a,b): #最小公倍数
        return a//Library.Gcd(a,b)*b

    @staticmethod
    def Divisors(a): # 約数列挙
        divisors = []
        for i in range(1,int(a**0.5)+1):
            if a%i==0:
                divisors.append(i)
                if i!=a//i:
                    divisors.append(a//i)
        divisors.sort()
        return divisors

class Prime():
    # コンストラクタ
    # エラストテネスの篩
    def __init__(self,num):
        self.num = num
        self.sieve = [0] * (self.num + 1)
        self.sieve[0] = -1
        self.sieve[1] = -1
        for i in range(2,self.num + 1):
            if not self.sieve[i]:
                self.sieve[i] = i
                for j in range(i * i,self.num + 1,i):
                    if self.sieve[j]:
                        self.sieve[j] = i
    
    # 素数判定
    def isPrime(self,num = None):
        if num is None:
            num = self.num
        if self.sieve[num] == num:
            return True
        else:
            return False
    
    # 素数列挙
    def PrimeNum(self,num = None):
        if num is None:
            num = self.num
        prime = []
        for i in range(2,num):
            if self.sieve[i] == i:
                prime.append(i)
        return prime
    
    # 素因数分解
    def PrimeFact(self,num = None):
        if num is None:
            num = self.num
        fact = []
        while self.sieve[num] != num:
            fact.append(self.sieve[num])
            num //= self.sieve[num]
        fact.append(num)
        return fact

def main():
    s = input()
    for i in range(len(s) - 1):
        if s[i] == 'A' and s[i + 1] == 'C':
            print('Yes')
            return
    print('No')
    return

if __name__=='__main__':
    main()
