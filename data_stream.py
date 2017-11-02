import random
import math
import numpy as np

max_ = 100000000000


def generate_numbers():

    numbers=[]
    map_count ={}
    np.random.seed(50)
	
    for i in range(10):
        numbers = np.random.uniform(0,1,10000000)
        numbers = np.square(numbers)
        numbers = np.floor(1/numbers)
        numbers[numbers>max] = max_

            #.append( int(1/(pow(random.random(),2))) if int(1/(pow(random.random(),2))) < max else max)

        for n in np.unique(numbers):
            if n not in  map_count:
                map_count[n] = 1
    return map_count
def count_zeros(n):

    count_z = 0
    index = len(n) - 1
    while (index >= 0):
        if n[index].__contains__('0'):
            count_z = count_z + 1
        else:
            break
        index = index - 1
    return count_z

def randomHash(prime=2654435761):
	a,b = random.randint(0,prime), random.randint(0,prime)
	def f(x):
		return int ( ((a*x + b) % prime) )
	return f

def numbers_distincts(num):
    map_count = generate_numbers()
    print 'numeros distitos real', map_count.__len__()

    r = []
    max_value = 0
    zeros = 0
    for i in xrange(num):
        r.append(0)
    hashes = [randomHash() for _ in range(num)]
    for key, value in  map_count.items():
       i = 0
       max_value = 0
       for hash in hashes:
           value_h = hash(key)
           value_b = bin(value_h)
           zeros = count_zeros(value_b)
           max_value = zeros
           if (pow(2,max_value) > r[i] ):
               r[i] = pow(2,max_value)
           i+=1



    median_average(25,r)



def median(list):

    list.sort()
    if len(list) % 2 == 0:
        n = len(list)
        mediana = (list[n / 2 - 1] + list[n / 2]) / 2
    else:
        mediana = list[len(list) / 2]

    return mediana

def median_average(div, list):
    median_r = []
    start = 0

    k=1

    average = []

    if len(list)%div == 0:
      for i in range(0,div):
            end =( (len(list)/div) * k) -1
            count = 0
            for j in range(start, end):
                print 'element j:', list[j]
                count = count +list[j];
            average .append(count/33)
            start = end+1
            k = k+1
            end = ((len(list) / div) * k) - 1
    print average

    print 'ola',median(average)













if __name__ == "__main__":
   numbers_distincts(825)