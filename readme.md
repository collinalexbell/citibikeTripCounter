# CitiBike trip counter

Just count number of trips in a data set from a particular station for now

## How to use

### Grab some data
`mkdir data`

then yeet some csvs into it from here:

https://s3.amazonaws.com/tripdata/index.html



### Build
```
mkdir build
cd build
cmake ..
make
cd ..
```

### Run the command (after building)
`./CitiBike -c -s "N 10 St & Berry St"`

## Its gonna be slow!

The CSV parser I am using is pretty bad. It doesn't do streaming. I can't iterate across a file stream and just count instances. It literally has to pull all the column values out into a vector. It is SLOWSLOWSLOW.

I built this project to troll NIMBYs on Twitter and it is good enough for that purpose.

