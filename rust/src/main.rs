//! This also causes error
//!
//! ```
//! fn hoge<'a>(v: &'a Vec<i64>) -> &'a i64 {
//!     // Of course this is error
//!     // &v[3]
//!     // This is error as well
//!     static A: i64 = 5;
//!     &A
//! }
//!
//! #[allow(unused_variables)]
//! fn main() {
//! let a = vec![1i64; 10];
//! let b = hoge(&a);
//! a[3] = 3;
//! }
//! ```

fn main() {
    let mut vec = vec![0i64; 10];
    vec[0] = 1;
    vec[1] = 1;
    vec[2] = 1;
    vec[3] = 1;

    let vref = &vec[3];

    println!("Before resize ref ptr: {:p}", vref);
    let _vec_dummy = vec![0i64; 10];

    // error!
    vec.resize(100, 0);
    println!("After resize ref ptr: {:p}", vref);
    println!("After resize addr: {:p}", &vec[3]);
}
